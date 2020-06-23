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
        Matrix4 objectToWorld;

        public RenderObject(Mesh objectMesh, Texture objectTexture, Shader objectShader)
        {
            mesh = objectMesh;
            texture = objectTexture;
            shader = objectShader;
        }

        public void render(Matrix4 worldToScreen, ref LightGroup lightGroup)
        {
            Matrix4 thisObjectToScreen = objectToWorld * worldToScreen;
            mesh.Render(shader, thisObjectToScreen, texture, ref lightGroup);
        }

        public void SetObjectToWorldMatrix(Matrix4 ObjectToWorld)
        {
            objectToWorld = ObjectToWorld;
            mesh.setObjectToWorldMatrix(objectToWorld);
        }
    }
}
