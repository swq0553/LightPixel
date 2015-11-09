<?xml version="1.0" encoding="utf-8"?>
<effect>
  <shader type="0" name="HelperVS">
    <![CDATA[
    #version 400
    layout (location = 0) in float VertexPosition;

   // uniform mat4 ModelViewMatrix;   
   // uniform mat4 ProjectionMatrix; 
    uniform vec3 position[3];      
    void main()
    {
      vec3 pos;
      if (VertexPosition < 0.5f)
      {
        pos = position[0];
      }
      else if (VertexPosition < 1.5f)
      {
        pos = position[1];
      }
      else if (VertexPosition < 2.5f)
      {
        pos = position[2];
      }

     //mat4 MVP = ProjectionMatrix*ModelViewMatrix;
     gl_Position = vec4(pos,1.0);      
    };
    ]]>
  </shader>
  <shader type="1" name="HelperPS">
    <![CDATA[
    #version 400
    uniform vec3 color;
   layout( location = 0 ) out vec4 FragColor; 
    void main() {
    FragColor  = vec4(color[0], color[1], color[2], 1.0);    
    };
    ]]>

</shader>
  <technique name="Helper">
    <pass name="p0">
      <program VS="HelperVS" PS="HelperPS" /> 
      <para type="mat4" name="ModelViewMatrix" />
      <para type="mat4" name="ProjectionMatrix" />
      <para type="vec4" name="color" />
      <para type="vec3v" name="position" />
    </pass>
  </technique>
</effect>