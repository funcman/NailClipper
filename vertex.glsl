uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;

in  vec3 position;
in  vec4 color;

out vec4 fragColor;

void main( void ) {
    gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.0);
    fragColor   = color;
}
