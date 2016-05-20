#ifdef GL_ES
out mediump vec4 fColor;
#else
out vec4 fColor;
#endif

void main( void ) {
    fColor = vec4(1.0, 0.0, 0.0, 1.0);
}
