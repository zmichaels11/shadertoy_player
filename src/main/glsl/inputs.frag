#version 300 es

precision mediump float;

uniform vec3 iResolution;
uniform float iTime;
uniform float iTimeDelta;
uniform int iFrame;
uniform float iFrameRate;
uniform float iChannelTime[4];
uniform vec3 iChannelResolution[4];
uniform vec4 iMouse;
uniform sampler2D iChannel[8];
uniform vec4 iDate;
uniform float iSampleRate;

in vec2 fragCoord;
out vec4 fragColor;

void mainImage(out vec4 fragColor, in vec2 fragCoord);

void main() {    
    mainImage(fragColor, fragCoord);
}