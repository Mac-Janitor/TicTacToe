#version 330

#ifdef GL_ES
#define LOWP lowp
precision mediump float;
#else
#define LOWP
#endif

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables
const float offset = 1.0 / 128.0;
const float smoothing = 1.0/16.0;

void main()
{
	// finalColor = texture(texture0, fragTexCoord);


	vec4 col = texture(texture0, fragTexCoord);
	if (col.a > 0.53)
		finalColor = fragColor;
	else 
	{
		float a = texture(texture0, vec2(fragTexCoord.x + offset, fragTexCoord.y)).a +
			texture(texture0, vec2(fragTexCoord.x, fragTexCoord.y - offset)).a +
			texture(texture0, vec2(fragTexCoord.x - offset, fragTexCoord.y)).a +
			texture(texture0, vec2(fragTexCoord.x, fragTexCoord.y + offset)).a;
		if (a > 0.0)
			// finalColor = vec4(0.0, 0.0, 0.0, 0.8);
			finalColor = vec4(1.0, 1.0, 1.0, 1.0);
		else
			finalColor = fragColor;
	}

    // Texel color fetching from texture sampler
    // NOTE: Calculate alpha using signed distance field (SDF)
    float distance = texture(texture0, fragTexCoord).a;
    float alpha = smoothstep(0.5 - smoothing, 0.5 + smoothing, distance);
    
    // Calculate final fragment color
    finalColor = vec4(finalColor.rgb, finalColor.a*alpha);	

}