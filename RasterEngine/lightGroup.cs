using System;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenTK;
using OpenTK.Graphics.OpenGL;

namespace INFOGR2019Tmpl8
{

    public class light
    {
        Vector3 position;
        Vector3 centerPosition;
        Vector3 color;
        Vector3 originalColor;
        double amplitude;

        public light(Vector3 lightPosition, Vector3 lightColor, double lightAmplitude)
        {
            position = lightPosition;
            centerPosition = lightPosition;
            color = lightColor;
            originalColor = color;
            amplitude = lightAmplitude;
        }

        public void update(double angle)
        {
            position.X = (float)(centerPosition.X + amplitude * Math.Cos(angle));
            position.Y = (float)(centerPosition.Y + amplitude * Math.Sin(angle));
            position.Z = (float)(centerPosition.Z + amplitude * Math.Cos(angle - 3.14 / 2));

            color.X = (float)(originalColor.X + 0.4 * Math.Cos(angle));
            color.Y = (float)(originalColor.Y + 0.4 * Math.Sin(angle));
            color.Z = (float)(originalColor.Z + 0.4 * Math.Cos(angle - 3.14 / 2));
        }

        public Vector3 getPosition()
        {
            return position;
        }

        public Vector3 getColor()
        {
            return color;
        }
    }
    public class LightGroup 
    {
        Stopwatch timer;
        float frameDuration;
        float angle; 
        const float PI = 3.1415926535f;
        List<light> lights;

        public LightGroup()
        {
            timer = new Stopwatch();
            frameDuration = 0;
            angle = 0;

            lights = new List<light>();
            lights.Add(new light(new Vector3(4.0f, 10.0f, 0.0f), new Vector3(1.5f, 1.5f, 1.5f), 3));
            lights.Add(new light(new Vector3(7.0f, 10.0f, 0.0f), new Vector3(1.5f, 1.5f, 1.5f), 5));
            lights.Add(new light(new Vector3(-4.0f, 10.0f, 0.0f), new Vector3(1.5f, 1.5f, 1.5f), 20));
            lights.Add(new light(new Vector3(-1.0f, 10.0f, 0.0f), new Vector3(1.5f, 1.5f, 1.5f), 15));
        }

        public void updateLights()
        {
            frameDuration = timer.ElapsedMilliseconds;
            timer.Reset();
            
            angle += 0.001f * frameDuration;
            if (angle > 2 * PI) angle -= 2 * PI;
            
            foreach(light pointlight in lights)
            {
                pointlight.update(angle);
            }

            timer.Start();
        }

        public Vector3 getLightPosition(int index)
        {
            return lights[index].getPosition();
        }
        public Vector3 getLightColor(int index)
        {
            return lights[index].getColor();
        }
    }
}
