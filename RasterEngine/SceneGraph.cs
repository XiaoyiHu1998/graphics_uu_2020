using System;
using System.Collections.Generic;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Template;
using OpenTK;
using OpenTK.Graphics.OpenGL;

namespace INFOGR2019Tmpl8
{
    class SceneGraph
    {
        Matrix4 objectToWorld;
        Matrix4 worldToScreen;
        List<GraphNode> collections;

        public SceneGraph(Matrix4 ObjectToWorld, Matrix4 WorldToScreen)
        {
            objectToWorld = ObjectToWorld;
            worldToScreen = WorldToScreen;
            collections = new List<GraphNode>();
        }

        public void addCollection(RenderObject renderObject)
        {
            collections.Add(new GraphNode(objectToWorld, 0));
            collections[collections.Count - 1].addRenderObjectToLayer(renderObject, 0);
        }

        public void addChildToCollectionOnLayer(RenderObject renderObject, int rootChild, int targetLayer)
        {
            collections[rootChild].addRenderObjectToLayer(renderObject, targetLayer);
        }

        public void transformCollectionOnLayer(Matrix4 transform, int rootChild, int targetLayer)
        {
            collections[rootChild].transformLayer(transform, targetLayer);
        }

        public void transformScene(Matrix4 transform)
        {
            foreach(GraphNode node in collections)
            {
                node.transformLayer(transform, 0);
            }
        }

        public void setWorldToScreenMatrix(Matrix4 newMatrix)
        {
            worldToScreen = newMatrix;
        }

        public void Render(ref LightGroup lightGroup)
        {
            foreach(GraphNode node in collections)
            {
                node.render(worldToScreen, ref lightGroup);
            }
        }

    }
}
