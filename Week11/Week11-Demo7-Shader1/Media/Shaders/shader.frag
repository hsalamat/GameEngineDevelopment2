uniform sampler2D texture;
uniform float opacity;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    gl_FragColor = pixel  vec4(1.0,1.0,1.0,opacity); 
}