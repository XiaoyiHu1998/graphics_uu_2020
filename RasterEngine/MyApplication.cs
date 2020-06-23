using System.Diagnostics;
using System.Drawing.Drawing2D;
using INFOGR2019Tmpl8;
using OpenTK;

namespace Template
{
	class MyApplication
	{
		// member variables
		public Surface screen;                  // background surface for printing etc.
		Mesh mesh, floor;                       // a mesh to draw using OpenGL
		const float PI = 3.1415926535f;         // PI
		float a = 0;                            // teapot rotation angle
		Stopwatch timer;                        // timer for measuring frame duration
		Shader shader;                          // shader to use for rendering
		Shader postproc;                        // shader to use for post processing
		Texture wood;                           // texture to use for rendering
		RenderTarget target;                    // intermediate render target
		ScreenQuad quad;                        // screen filling quad for post processing
		bool useRenderTarget = true;

		Matrix4 objectToWorld;
		Matrix4 worldToScreen;
		Matrix4 childMatrix;

		LightGroup lightGroup;
		SceneGraph scenegraph;

		// initialize
		public void Init()
		{
			// load teapot
			mesh = new Mesh( "../../assets/teapot.obj" );
			floor = new Mesh( "../../assets/floor.obj" );
			// initialize stopwatch
			timer = new Stopwatch();
			timer.Reset();
			timer.Start();
			// create shaders
			shader = new Shader( "../../shaders/vs.glsl", "../../shaders/fs.glsl" );
			postproc = new Shader( "../../shaders/vs_post.glsl", "../../shaders/fs_post.glsl" );
			// load a texture
			wood = new Texture( "../../assets/wood.jpg" );
			// create the render target
			target = new RenderTarget( screen.width, screen.height );
			quad = new ScreenQuad();

			Matrix4 objectToWorld = Matrix4.CreateScale(0.6f) * Matrix4.CreateFromAxisAngle(new Vector3(0, 1, 0), a);
			Matrix4 worldToScreen = Matrix4.CreateTranslation(new Vector3(0, -14.5f, 0))
									* Matrix4.CreateFromAxisAngle(new Vector3(1, 0, 0), PI / 2)
									* Matrix4.CreatePerspectiveFieldOfView(1.2f, 1.3f, .1f, 1000);

			lightGroup = new LightGroup();
			scenegraph = new SceneGraph(objectToWorld, worldToScreen);

			scenegraph.addCollection(new RenderObject(mesh, wood, shader));

            scenegraph.addChildToCollectionOnLayer(new RenderObject(mesh, wood, shader), 0, 1);
            childMatrix = Matrix4.CreateScale(0.5f) * Matrix4.CreateTranslation(7, -3, 2);
            scenegraph.transformCollectionOnLayer(childMatrix, 0, 1);

            scenegraph.addCollection(new RenderObject(floor, wood, shader));
            scenegraph.transformScene(Matrix4.CreateScale(1.3f));
            scenegraph.transformCollectionOnLayer(Matrix4.CreateScale(1.3f), 1, 0);
        }

		// tick for background surface
		public void Tick()
		{
			screen.Clear( 0 );
			screen.Print( "hello world", 2, 2, 0xffff00 );
		}

		// tick for OpenGL rendering code
		public void RenderGL()
		{
			// measure frame duration
			float frameDuration = timer.ElapsedMilliseconds;
			timer.Reset();
			timer.Start();

			// update rotation
			a += 0.001f * frameDuration;
			if( a > 2 * PI ) a -= 2 * PI;

            objectToWorld = Matrix4.CreateFromAxisAngle(new Vector3(0, 1, 0), a / 100);
            scenegraph.transformCollectionOnLayer(objectToWorld, 0, 0);

            //worldToScreen = Matrix4.CreateTranslation(new Vector3(0, -14.5f, 0))
            //                * Matrix4.CreateFromAxisAngle(new Vector3(1, 0, 0), PI / 2)
            //                * Matrix4.CreatePerspectiveFieldOfView(1.2f, 1.3f, .1f, 1000);
            //scenegraph.setWorldToScreenMatrix(worldToScreen);

            //childMatrix = Matrix4.CreateFromAxisAngle(new Vector3(0, 1, 0), a);
            //scenegraph.transformCollectionOnLayer(childMatrix, 0, 1);

            lightGroup.updateLights();

			if( useRenderTarget )
			{
				// enable render target
				target.Bind();

                // render scene to render target
                //mesh.Render(shader, objectToWorld, worldToScreen, wood, ref lightGroup);
                //floor.Render(shader, objectToWorld, worldToScreen, wood, ref lightGroup);
                scenegraph.Render(ref lightGroup);

                // render quad
                target.Unbind();
				quad.Render( postproc, target.GetTextureID() );
			}
			else
			{
				// render scene directly to the screen
				mesh.Render( shader, objectToWorld, worldToScreen, wood, ref lightGroup);
				floor.Render( shader, objectToWorld, worldToScreen, wood, ref lightGroup);
			}
		}
	}
}