#version 330
 
uniform sampler2D texture_1;
uniform sampler2D texture_2;
uniform int textures;


in vec2 texcoord;

layout(location = 0) out vec4 out_color;

void main()
{
	vec4 color1 = texture2D(texture_1, texcoord);  
	vec4 color2 = texture2D(texture_2, texcoord);         

	if (color2.a == 0) {
		discard;
	}
	if (textures ==1){
		out_color = mix(color1, color2, 0.5f);
		}
	else{
		out_color = color1; 
	}
}