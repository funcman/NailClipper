#ifdef GL_ES
in  mediump vec4        fragColor;
in  mediump vec2        fragTexCoord;
out mediump vec4        color;
#else
in          vec4        fragColor;
in          vec2        fragTexCoord;
out         vec4        color;
#endif
uniform     bool        useColorAdd;
uniform     bool        texInvalid;
uniform     sampler2D   texSampler;

void main( void ) {
    if (texInvalid) {
        color = fragColor;
    }else {
        if (useColorAdd) {
#ifdef GL_ES
            mediump vec4    texColor;
#else
            vec4            texColor;
#endif
            texColor    = texture(texSampler, fragTexCoord);
            color       = vec4(texColor.rgb+fragColor.rgb, texColor.a*fragColor.a);
        }else {
            color       = texture(texSampler, fragTexCoord) * fragColor;
        }
    }
}
