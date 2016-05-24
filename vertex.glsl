uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;

in  vec3 position;
in  vec4 color;
in  vec2 texCoord;

out vec4 fragColor;
out vec2 fragTexCoord;

void main( void ) {
    gl_Position     = projectionMatrix * modelViewMatrix * vec4(position, 1.0);
    fragColor       = color;
    fragTexCoord    = texCoord;
}
