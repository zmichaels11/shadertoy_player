#version 300 es

precision mediump float;

const vec4[4] VERTEX_SELECT = vec4[] (
    vec4(-1.0, 1.0, 0.0, 1.0), vec4(-1.0, -1.0, 0.0, 1.0),
    vec4(1.0, 1.0, 0.0, 1.0), vec4(1.0, -1.0, 0.0, 1.0));

const vec2[4] FRAGMENT_SELECT = vec2[] (
    vec2(0.0, 0.0), vec2(0.0, 1.0),
    vec2(1.0, 0.0), vec2(1.0, 1.0));


out vec2 fragCoord;

uniform vec3 iResolution;

void main() {
    gl_Position = VERTEX_SELECT[gl_VertexID];
    fragCoord = iResolution.xy * FRAGMENT_SELECT[gl_VertexID];
}