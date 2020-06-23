using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Template;
using OpenTK;
using OpenTK.Graphics.OpenGL;

namespace INFOGR2019Tmpl8
{
    class GraphNode
    {
        int layer;
        Matrix4 transform;
        List<GraphNode> child;
        List<RenderObject> objects;

        public GraphNode(Matrix4 matrix, int Layer)
        {
            layer = Layer;
            transform = matrix;
            child = new List<GraphNode>();
            objects = new List<RenderObject>();
        }

        public void transformLayer(Matrix4 transformMatrix, int targetLayer)
        {
            if(layer == targetLayer)
            {
                transformNodeAndChildren(transformMatrix);
            }
            else if(targetLayer > layer && child.Count > 0)
            {
                child[0].transformLayer(transformMatrix, targetLayer);
            }
        }

        private void transformNodeAndChildren(Matrix4 transformMatrix)
        {
            transform *= transformMatrix;
            if(child.Count > 0)
            {
                child[0].transformNodeAndChildren(transformMatrix);
            }
        }

        public void addRenderObjectToLayer(RenderObject renderObject, int targetLayer)
        {
            if(targetLayer > layer && child.Count == 0)
            {
                child.Add(new GraphNode(transform, layer + 1));
                child[0].addRenderObjectToLayer(renderObject, targetLayer);
            }
            if (layer == targetLayer)
            {
                objects.Add(renderObject);
            }
            else
            {
                child[0].addRenderObjectToLayer(renderObject, targetLayer);
            }
        }

        public void render(Matrix4 worldToScreen, ref LightGroup lightGroup)
        {
            foreach(RenderObject renderObject in objects)
            {
                renderObject.render(transform, worldToScreen, ref lightGroup);
            }
            if(child.Count > 0)
            {
                child[0].render(worldToScreen, ref lightGroup);
            }
        }
    }
}
