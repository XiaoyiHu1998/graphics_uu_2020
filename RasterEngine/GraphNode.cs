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
        bool dirtyFlag;
        Matrix4 objectToWorld;
        Matrix4 translation;
        Matrix4 scale;
        Matrix4 rotation;
        List<GraphNode> child;
        List<RenderObject> objects;

        public GraphNode(Matrix4 Translation, Matrix4 Rotation, Matrix4 Scale, int Layer)
        {
            layer = Layer;
            translation = Translation;
            rotation = Rotation;
            scale = Scale;
            objectToWorld = translation * rotation * scale;
            child = new List<GraphNode>();
            objects = new List<RenderObject>();

            dirtyFlag = false;
        }

        public void addRenderObjectToLayer(RenderObject renderObject, int targetLayer)
        {
            if(targetLayer > layer && child.Count == 0)
            {
                child.Add(new GraphNode(translation, rotation, scale, layer + 1));
                child[0].addRenderObjectToLayer(renderObject, targetLayer);
            }
            if (layer == targetLayer)
            {
                objects.Add(renderObject);
                objects[objects.Count - 1].SetObjectToWorldMatrix(objectToWorld);
            }
            else
            {
                child[0].addRenderObjectToLayer(renderObject, targetLayer);
            }
        }

        public void render(Matrix4 worldToScreen, ref LightGroup lightGroup)
        {
            if (dirtyFlag)
            {
                objectToWorld = translation * rotation * scale;
                foreach (RenderObject renderObject in objects)
                {
                    renderObject.SetObjectToWorldMatrix(objectToWorld);
                }
            }
            foreach(RenderObject renderObject in objects)
            {
                renderObject.render(worldToScreen, ref lightGroup);
            }
            if(child.Count > 0)
            {
                child[0].render(worldToScreen, ref lightGroup);
            }
        }

        public void setTranslation(Matrix4 Translation, int targetLayer)
        {
            if(layer >= targetLayer)
            {
                translation *= Translation;
                dirtyFlag = true;
            }
            if(child.Count > 0)
            {
                child[0].setTranslation(Translation, targetLayer);
            }
        }
        public void setRotation(Matrix4 Rotation, int targetLayer)
        {
            if (layer >= targetLayer)
            {
                rotation *= Rotation;
                dirtyFlag = true;
            }
            if (child.Count > 0)
            {
                child[0].setRotation(Rotation, targetLayer);
            }
        }
        public void setScale(Matrix4 Scale, int targetLayer)
        {
            if (layer >= targetLayer)
            {
                scale *= Scale;
                dirtyFlag = true;
            }
            if (child.Count > 0)
            {
                child[0].setScale(Scale, targetLayer);
            }
        }
    }
}
