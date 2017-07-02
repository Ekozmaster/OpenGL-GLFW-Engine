#version 300 es

precision mediump float;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

in vec3 Normal;
in vec3 FragPos;

const float ambientLightStrenght = 0.1;
const vec3 lightColor = vec3(1.0, 0.6, 1.0);
const float lightEnergy = 1.0;
const vec3 lightPos = vec3(1.0, 1.0, 1.0);

out vec4 outColor;

void main(){
    // Diffuse Lightning
    vec3 lightDiff = normalize(lightPos - FragPos);
    vec3 faceNormal = normalize(Normal);
    float dotProduct = dot(lightDiff, faceNormal);
    float dotMultiplier = max(dotProduct, 0.0);
    
    float finalAmbient = ambientLightStrenght + min(dotProduct, 0.0) * ambientLightStrenght * 0.5;
    
    // Distance Fading
    float dist = (lightDiff.x * lightDiff.x + lightDiff.y * lightDiff.y + lightDiff.z * lightDiff.z);
    float finalEnergy = lightEnergy / dist;
    
    vec3 color = (finalAmbient + dotMultiplier) * lightColor * finalEnergy;
    outColor = vec4(color, 1.0);
}