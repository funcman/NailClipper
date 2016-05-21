#ifdef GL_ES
in  mediump vec4 fragColor;
out mediump vec4 color;
#else
in  vec4 fragColor;
out vec4 color;
#endif

void main( void ) {
    color = fragColor;
}
