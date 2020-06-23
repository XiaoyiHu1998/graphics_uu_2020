using System;
using System.Diagnostics;
using System.Drawing.Drawing2D;
using INFOGR2019Tmpl8;
using OpenTK;
using OpenTK.Input;

namespace Template
{
	class MyApplication
	{
		// member variables
		public Surface screen;                  // background surface for printing etc.
		Mesh mesh0;
		Mesh mesh1;
		Mesh mesh2;
		Mesh mesh3;
		Mesh mesh4;
		Mesh mesh5;
		Mesh mesh6;
		Mesh mesh7;
		Mesh floor0;
		Mesh floor1;
		Mesh floor2;
		Mesh floor3;
		Mesh floor4;
		const float PI = 3.1415926535f;         // PI
		float a = 2;                            // teapot rotation angle
		float a2 = 0;
		Stopwatch timer;                        // timer for measuring frame duration
		Shader shader;                          // shader to use for rendering
		Shader postproc;                        // shader to use for post processing
		Texture wood;
		RenderTarget target;                    // intermediate render target
		ScreenQuad quad;                        // screen filling quad for post processing
		bool useRenderTarget = true;

		Matrix4 objectToWorld;
		Matrix4 viewportMatrix;
		Matrix4 worldToScreen;

		SceneGraph scenegraph;
		KeyboardState keyboard;
		MouseState mouse;

		// initialize
		public void Init()
		{
			// load teapot
			mesh0 = new Mesh("../../assets/teapot.obj");
			mesh1 = new Mesh("../../assets/teapot.obj");
			mesh2 = new Mesh("../../assets/teapot.obj");
			mesh3 = new Mesh("../../assets/teapot.obj");
			mesh4 = new Mesh("../../assets/teapot.obj");
			mesh5 = new Mesh("../../assets/teapot.obj");
			mesh6 = new Mesh("../../assets/teapot.obj");
			mesh7 = new Mesh("../../assets/teapot.obj");
			floor0 = new Mesh("../../assets/floor.obj");
			floor1 = new Mesh("../../assets/floor.obj");
			floor2 = new Mesh("../../assets/floor.obj");
			floor3 = new Mesh("../../assets/floor.obj");
			floor4 = new Mesh("../../assets/floor.obj");
			// initialize stopwatch
			timer = new Stopwatch();
			timer.Reset();
			timer.Start();
			// create shaders
			shader = new Shader( "../../shaders/vs.glsl", "../../shaders/fs.glsl" );
			postproc = new Shader( "../../shaders/vs_post.glsl", "../../shaders/fs_post.glsl" );
			// load a texture
			wood = new Texture("../../assets/wood.jpg");
			// create the render target
			target = new RenderTarget( screen.width, screen.height );
			quad = new ScreenQuad();
			keyboard = Keyboard.GetState();
			mouse = Mouse.GetState();

			objectToWorld = Matrix4.CreateScale(0.6f) * Matrix4.CreateFromAxisAngle(new Vector3(0, 1, 0), a);
			viewportMatrix = Matrix4.CreateTranslation(new Vector3(0, -14.5f, 0)) * Matrix4.CreateFromAxisAngle(new Vector3(1, 0, 0), PI / 2);
			worldToScreen = viewportMatrix * Matrix4.CreatePerspectiveFieldOfView(1.2f, 1.3f, .1f, 1000);

			scenegraph = new SceneGraph(objectToWorld, worldToScreen);

			scenegraph.addCollection(new RenderObject(mesh0, wood, shader));
			scenegraph.addChildToCollectionOnLayer(new RenderObject(mesh0, wood, shader), 0, 1);
			scenegraph.addChildToCollectionOnLayer(new RenderObject(mesh1, wood, shader), 0, 2);
			scenegraph.addChildToCollectionOnLayer(new RenderObject(mesh2, wood, shader), 0, 3);
			scenegraph.addChildToCollectionOnLayer(new RenderObject(mesh3, wood, shader), 0, 4);
			scenegraph.addChildToCollectionOnLayer(new RenderObject(mesh4, wood, shader), 0, 5);
			scenegraph.addChildToCollectionOnLayer(new RenderObject(mesh5, wood, shader), 0, 6);
			scenegraph.addChildToCollectionOnLayer(new RenderObject(mesh6, wood, shader), 0, 7);
			scenegraph.addChildToCollectionOnLayer(new RenderObject(mesh7, wood, shader), 0, 8);

			scenegraph.setTranslation(Matrix4.CreateTranslation(2, 0, 2), 0, 1);
			scenegraph.setTranslation(Matrix4.CreateTranslation(2, 0, 2), 0, 2);
			scenegraph.setTranslation(Matrix4.CreateTranslation(2, 0, 2), 0, 3);
			scenegraph.setTranslation(Matrix4.CreateTranslation(2, 0, 2), 0, 4);
			scenegraph.setTranslation(Matrix4.CreateTranslation(2, 0, 2), 0, 5);
			scenegraph.setTranslation(Matrix4.CreateTranslation(2, 0, 2), 0, 6);
			scenegraph.setTranslation(Matrix4.CreateTranslation(2, 0, 2), 0, 7);
			scenegraph.setTranslation(Matrix4.CreateTranslation(2, 0, 2), 0, 8);

            scenegraph.setRotation(Matrix4.CreateRotationY(0.3f), 0, 1);
			scenegraph.setRotation(Matrix4.CreateRotationY(0.3f), 0, 2);
			scenegraph.setRotation(Matrix4.CreateRotationY(0.3f), 0, 3);
			scenegraph.setRotation(Matrix4.CreateRotationY(0.3f), 0, 4);
			scenegraph.setRotation(Matrix4.CreateRotationY(0.3f), 0, 5);
			scenegraph.setRotation(Matrix4.CreateRotationY(0.3f), 0, 6);
			scenegraph.setRotation(Matrix4.CreateRotationY(0.3f), 0, 7);
			scenegraph.setRotation(Matrix4.CreateRotationY(0.3f), 0, 8);

			scenegraph.setScaleGlobal(Matrix4.CreateScale(0.4f));

			scenegraph.addCollection(new RenderObject(floor0, wood, shader));
			scenegraph.setTranslation(Matrix4.CreateTranslation(-8, -8, 2), 1, 0);

			scenegraph.addChildToCollectionOnLayer(new RenderObject(floor1, wood, shader), 1, 1);
			scenegraph.setTranslation(Matrix4.CreateTranslation(15, -5, 0), 1, 1);

			scenegraph.addChildToCollectionOnLayer(new RenderObject(floor2, wood, shader), 1, 2);
			scenegraph.setTranslation(Matrix4.CreateTranslation(-15, -1, -15), 1, 2);

			scenegraph.addChildToCollectionOnLayer(new RenderObject(floor1, wood, shader), 1, 3);
			scenegraph.setTranslation(Matrix4.CreateTranslation(15, -5, 0), 1, 3);


		}

		// tick for background surface
		public void Tick()
		{
			screen.Clear( 0 );
			screen.Print( "hello world", 2, 2, 0xffff00 );
		}

		public void updateViewportPosition()
		{
			float transformStrength = 0.2f;
			keyboard = Keyboard.GetState();
			mouse = Mouse.GetState();
			if (keyboard.IsKeyDown(Key.W))
			{
				viewportMatrix *= Matrix4.CreateTranslation(0, -1 * transformStrength, 0);
			}
			if (keyboard.IsKeyDown(Key.S))
			{
				viewportMatrix *= Matrix4.CreateTranslation(0, transformStrength, 0);
			}
			if (keyboard.IsKeyDown(Key.A))
			{
				viewportMatrix *= Matrix4.CreateTranslation(transformStrength, 0, 0);
			}
			if (keyboard.IsKeyDown(Key.D))
			{
				viewportMatrix *= Matrix4.CreateTranslation(-1 * transformStrength, 0, 0);
			}
			if (mouse.IsButtonDown(MouseButton.Right))
			{
				viewportMatrix *= Matrix4.CreateTranslation(0, 0, -1 * transformStrength);
			}
			if (mouse.IsButtonDown(MouseButton.Left))
			{
				viewportMatrix *= Matrix4.CreateTranslation(0, 0, transformStrength);
			}
			if (keyboard.IsKeyDown(Key.Q))
			{
				viewportMatrix *= Matrix4.CreateRotationZ( 0.3f * -1 * transformStrength);
			}
			if (keyboard.IsKeyDown(Key.E))
			{
				viewportMatrix *= Matrix4.CreateRotationZ(0.3f * transformStrength);
			}

			scenegraph.setWorldToScreenMatrix(viewportMatrix * Matrix4.CreatePerspectiveFieldOfView(1.2f, 1.3f, .1f, 1000));
		}

		// tick for OpenGL rendering code
		public void RenderGL()
		{
			// measure frame duration
			float frameDuration = timer.ElapsedMilliseconds;
			timer.Reset();
			timer.Start();

			// update rotation
            a2 += 0.005f * frameDuration;
            if (a2 > 2 * PI) a2 -= 2 * PI;

            Matrix4 rotationMatrix0 = Matrix4.CreateRotationY(a / 100);
			Matrix4 rotationMatrix1 = Matrix4.CreateRotationX(a / 270);
			Matrix4 rotationMatrix2 = Matrix4.CreateRotationZ(a / 530);
			Matrix4 rotationMatrix3 = Matrix4.CreateRotationY(a / -890);

			Matrix4 translationMatrix = Matrix4.CreateTranslation(Math.Max(Math.Min((float)Math.Sin(a2), 0.5f), -0.5f),0 ,0);

			scenegraph.setRotation(rotationMatrix0, 0, 0);
			//scenegraph.setRotation(rotationMatrix1, 0, 0);
			scenegraph.setRotation(rotationMatrix2, 0, 0);

			scenegraph.setTranslation(translationMatrix, 0, 0);

			scenegraph.setRotation(rotationMatrix3, 1, 0);


			updateViewportPosition();
            if ( useRenderTarget )
			{
				// enable render target
				target.Bind();

                // render scene to render target
                //mesh.Render(shader, objectToWorld, worldToScreen, wood, ref lightGroup);
                //floor.Render(shader, objectToWorld, worldToScreen, wood, ref lightGroup);
                scenegraph.Render();

                // render quad
                target.Unbind();
				quad.Render( postproc, target.GetTextureID() );
			}
			else
			{
				// render scene directly to the screen
			}
		}
	}
}