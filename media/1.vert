#version 150

in float VertexPosition;
//uniform float position[9];
//uniform vec3 position[3];
void main() {
    // does not alter the verticies at all
    vec3 pos;
      if (VertexPosition < 0.5f)
      {
       // pos = position[0];
       pos = vec3(0.0f, 0.8f, 0.0f);
       //pos = vec3(position[0], position[1], position[2]);
      }
      else if (VertexPosition < 1.5f)
      {
       // pos = position[1];
        pos = vec3(-0.8f, -0.8f, 0.0f);
        //pos = vec3(position[3], position[4], position[5]);
      }
      else if (VertexPosition < 2.5f)
      {
       // pos = position[2];
        pos = vec3(0.8f, -0.8f, 0.0f);
        //pos = vec3(position[6], position[7], position[8]);
      }

    gl_Position = vec4(pos, 1);
}