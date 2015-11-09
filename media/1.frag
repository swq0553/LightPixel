#version 150

out vec4 finalColor;
uniform float color[3];
void main() {
    //set every drawn pixel to white
    finalColor = vec4(color[0], color[1], color[2], 1.0);
}