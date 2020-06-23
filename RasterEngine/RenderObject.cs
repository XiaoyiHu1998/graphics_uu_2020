using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Template;
using OpenTK;
using OpenTK.Graphics.OpenGL;
using System.Drawing.Drawing2D;

namespace INFOGR2019Tmpl8
{
    class RenderObject
    {
        Mesh mesh;
        Texture texture;
        Shader shader;

        Matrix4 translation;
        Matrix4 scale;
        Matrix4 rotation;

        public RenderObject(Mesh objectMesh, Texture objectTexture, Shader objectShader)
        {
            mesh = objectMesh;
            texture = objectTexture;
            shader = objectShader;

            translation = new Matrix4();
            scale = new Matrix4();
            rotation = new Matrix4();
        }

        public void render(Matrix4 objectToWorld, Matrix4 worldToScreen, ref LightGroup lightGroup)
        {
            Matrix4 thisObjectToWorld = objectToWorld;
            Matrix4 thisObjectToScreen = thisObjectToWorld * worldToScreen;
            mesh.Render(shader, thisObjectToWorld, thisObjectToScreen, texture, ref lightGroup);
        }
    }
}
