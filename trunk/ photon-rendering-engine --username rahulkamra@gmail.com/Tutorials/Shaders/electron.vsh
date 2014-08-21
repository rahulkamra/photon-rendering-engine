layout (location = 0) in vec3 position;
layout (location = 1) in vec3 inColor;
layout (location = 2) in vec3 normal;



uniform  mat4  mvp;
uniform  mat4  modelToWorld;
uniform  vec3 cameraWorld;

out vec3 color;



