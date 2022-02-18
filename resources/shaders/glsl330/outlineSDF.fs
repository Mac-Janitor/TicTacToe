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

const float smoothing = 1.0/16.0;
const float outlineWidth = 5.0/16.0;
const float outerEdgeCenter = 0.5 - outlineWidth;

const vec3 outlineColor = vec3(1.0, 1.0, 1.0);

void main()
{
    float distance = texture(texture0, fragTexCoord).a;
    float alpha = smoothstep(outerEdgeCenter - smoothing, outerEdgeCenter + smoothing, distance);
    float border = smoothstep(0.5 - smoothing, 0.5 + smoothing, distance);
    finalColor = vec4( mix(outlineColor.rgb, fragColor.rgb, border), alpha );
}