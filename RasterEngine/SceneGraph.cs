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
        LightGroup lightGroup;
        List<GraphNode> collections;

        public SceneGraph(Matrix4 ObjectToWorld, Matrix4 WorldToScreen)
        {
            objectToWorld = ObjectToWorld;
            worldToScreen = WorldToScreen;
            collections = new List<GraphNode>();
            lightGroup = new LightGroup();
        }

        public void addCollection(RenderObject renderObject)
        {
            collections.Add(new GraphNode(Matrix4.CreateTranslation(0,0,0), Matrix4.CreateScale(1,1,1), Matrix4.CreateRotationX(0), 0));
            collections[collections.Count - 1].addRenderObjectToLayer(renderObject, 0);
        }

        public void addChildToCollectionOnLayer(RenderObject renderObject, int rootChild, int targetLayer)
        {
            collections[rootChild].addRenderObjectToLayer(renderObject, targetLayer);
        }

        public void setWorldToScreenMatrix(Matrix4 newMatrix)
        {
            worldToScreen = newMatrix;
        }

        public void Render()
        {
            lightGroup.updateLights();
            foreach (GraphNode node in collections)
            {
                node.render(worldToScreen, ref lightGroup);
            }
        }

        public void setTranslation(Matrix4 Translation, int collectionID, int targetLayer)
        {
            collections[collectionID].setTranslation(Translation, targetLayer);
        }
        public void setRotation(Matrix4 Rotation, int collectionID, int targetLayer)
        {
            collections[collectionID].setRotation(Rotation, targetLayer);
        }
        public void setScale(Matrix4 Scale, int collectionID, int targetLayer)
        {
            collections[collectionID].setScale(Scale, targetLayer);
        }
        public void setTranslationGlobal(Matrix4 Translation)
        {
            foreach (GraphNode collection in collections)
            {
                collection.setTranslation(Translation, 0);
            }
        }
        public void setRotationGlobal(Matrix4 Rotation)
        {
            foreach (GraphNode collection in collections)
            {
                collection.setRotation(Rotation, 0);
            }
        }
        public void setScaleGlobal(Matrix4 Scale)
        {
            foreach (GraphNode collection in collections)
            {
                collection.setScale(Scale, 0);
            }
        }

    }
}
