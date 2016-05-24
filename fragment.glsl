#ifdef GL_ES
in  mediump vec4 fragColor;
in  mediump vec2 fragTexCoord;
out mediump vec4 color;
#else
in  vec4 fragColor;
in  vec2 fragTexCoord;
out vec4 color;
#endif
uniform bool        texIsInvalid;
uniform sampler2D   texSampler;

void main( void ) {
    if (texIsInvalid) {
        color = fragColor;
    }else {
        color = texture(texSampler, fragTexCoord) * fragColor;
    }
}
