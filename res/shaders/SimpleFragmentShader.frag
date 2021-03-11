#version 330 core

in vec3 vColor;
in vec2 vTexture;
out vec4 color;


uniform sampler2D ourTexture;
uniform float color_or_texture;

void main()
{
    if(color_or_texture==0)
        color = texture(ourTexture, vTexture);
    else
        color = vec4(vColor, 0.0);
}
