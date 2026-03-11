#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>  
#include <vector>

// ===== DEINE STRUKTUREN UND FUNKTIONEN VOR main() DEFINIEREN =====

struct dreiecke {
    float x1, y1, z1;  // JETZT MIT Z!
    float x2, y2, z2;
    float x3, y3, z3;
    float r, g, b;
};



std::vector<dreiecke> Dreiecke;

void erstelleDreieck(float x1, float y1, float z1,
    float x2, float y2, float z2,
    float x3, float y3, float z3,
    float r, float g, float b) {
    dreiecke neu;

    neu.x1 = x1; neu.y1 = y1; neu.z1 = z1;
    neu.x2 = x2; neu.y2 = y2; neu.z2 = z2;
    neu.x3 = x3; neu.y3 = y3; neu.z3 = z3;

    neu.r = r; neu.g = g; neu.b = b;

    Dreiecke.push_back(neu);
}
void erstelleQuadrat(
    float posx, float posy,
    float höhe, float breite,
    float r, float g, float b) {

    //erstellt quadrat 

    dreiecke neu1; // Dreieck 1 (links unten, rechts unten, links oben)
    dreiecke neu2; // Dreieck 2 (rechts unten, rechts oben, links oben)

    neu1.x1 = posx;              neu1.y1 = posy;              neu1.z1 = 0; // links unten
    neu1.x2 = posx + breite;     neu1.y2 = posy;              neu1.z2 = 0; // rechts unten
    neu1.x3 = posx;              neu1.y3 = posy + höhe;       neu1.z3 = 0; // links oben

    neu2.x1 = posx + breite;     neu2.y1 = posy;              neu2.z1 = 0; // rechts unten
    neu2.x2 = posx + breite;     neu2.y2 = posy + höhe;       neu2.z2 = 0; // rechts oben
    neu2.x3 = posx;              neu2.y3 = posy + höhe;       neu2.z3 = 0; // links oben

    // Farben zuweisen
    neu1.r = r; neu1.g = g; neu1.b = b;
    neu2.r = r; neu2.g = g; neu2.b = b;

    // Zur Liste hinzufügen
    Dreiecke.push_back(neu1);
    Dreiecke.push_back(neu2);
}

std::vector<float> dreieckeZuVertices() {
    std::vector<float> vertices;

    for (const auto& d : Dreiecke) {
        // Punkt 1: x, y, z, r, g, b
        vertices.push_back(d.x1);
        vertices.push_back(d.y1);
        vertices.push_back(d.z1);  
        vertices.push_back(d.r);
        vertices.push_back(d.g);
        vertices.push_back(d.b);

        // Punkt 2
        vertices.push_back(d.x2);
        vertices.push_back(d.y2);
        vertices.push_back(d.z2);  // Z war vergessen!
        vertices.push_back(d.r);
        vertices.push_back(d.g);
        vertices.push_back(d.b);

        // Punkt 3
        vertices.push_back(d.x3);
        vertices.push_back(d.y3);
        vertices.push_back(d.z3);  // Z war vergessen!
        vertices.push_back(d.r);
        vertices.push_back(d.g);
        vertices.push_back(d.b);
    }

    return vertices;
}
enum Tasten
{
    MouseRechts,
    MouseLinks,

    Key_A, Key_B, Key_C, Key_D, Key_E, Key_F, Key_G, Key_H, Key_I, Key_J, Key_K, Key_L, Key_M,
    Key_N, Key_O, Key_P, Key_Q, Key_R, Key_S, Key_T, Key_U, Key_V, Key_W, Key_X, Key_Y, Key_Z
};

GLFWwindow* window; 

bool IstTasteGedrückt(Tasten taste) {
    switch (taste) {
    case MouseRechts:
        return glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
    case MouseLinks:
        return glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    case Key_A: return glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
    case Key_B: return glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS;
    case Key_C: return glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS;
    case Key_D: return glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;
    case Key_E: return glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS;
    case Key_F: return glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS;
    case Key_G: return glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS;
    case Key_H: return glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS;
    case Key_I: return glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS;
    case Key_J: return glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS;
    case Key_K: return glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS;
    case Key_L: return glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS;
    case Key_M: return glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS;
    case Key_N: return glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS;
    case Key_O: return glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS;
    case Key_P: return glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS;
    case Key_Q: return glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS;
    case Key_R: return glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS;
    case Key_S: return glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
    case Key_T: return glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS;
    case Key_U: return glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS;
    case Key_V: return glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS;
    case Key_W: return glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
    case Key_X: return glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS;
    case Key_Y: return glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS;
    case Key_Z: return glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS;

    default:
        return false;
    }
}

// ===== MAIN FUNKTION =====

int main(void)
{

    float hausX = -0.5f;  // Startposition
    float hausY = -0.5f;
    float speed = 0.0001f;


    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1040, 1080, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // GLAD initialisieren
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return -1;
    }

    // Vertex Shader
    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "layout (location = 1) in vec3 aColor;\n"
        "out vec3 ourColor;\n"
        "uniform float offset;\n"
        "void main()\n"
        "{\n"
        "gl_Position = vec4(aPos.x + offset, aPos.y , aPos.z, 1.0);\n"
        "   ourColor = aColor;\n"
        "}\0";

    // Fragment Shader
    const char* fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "in vec3 ourColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(ourColor, 1.0);\n"
        "}\n\0";

    // Shader kompilieren
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // ===== HIER ERSTELLST DU DEINE DREIECKE =====

    
    

    


    // ===== DREIECKE IN VERTICES KONVERTIEREN =====
    std::vector<float> vertexDaten = dreieckeZuVertices();

    // OpenGL Buffer vorbereiten
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Jetzt mit den echten Daten füllen!
    glBufferData(GL_ARRAY_BUFFER, vertexDaten.size() * sizeof(float),
        vertexDaten.data(), GL_STATIC_DRAW);

    // Position (Location = 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Farbe (Location = 1)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
        (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    float position = 0.0f;
    float geschwindigkeit = 0.001f;  // Schneller gemacht

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // ===== WICHTIG: Alte Dreiecke löschen! =====
        Dreiecke.clear();

        // ===== Tastatur-Eingabe =====
        if (IstTasteGedrückt(Key_D))
            hausX += speed;
        if (IstTasteGedrückt(Key_A))
            hausX -= speed;
        if (IstTasteGedrückt(Key_W))
            hausY += speed;
        if (IstTasteGedrückt(Key_S))
            hausY -= speed;

        // ===== Haus an NEUER Position mit hausX erstellen =====
        // ===== Haus an NEUER Position mit hausX und hausY erstellen =====
        erstelleQuadrat(//haus
            hausX, hausY,
            1.0f, 1.0f,
            1.0f, 0.0f, 1.0f
        );

        erstelleDreieck(//Dach links (das rote Dach)
            hausX - 0.2f, hausY + 1.0f, 0.0f,           // linke untere Ecke
            hausX + 1.2f, hausY + 1.0f, 0.0f,           // rechte untere Ecke  
            hausX + 0.5f, hausY + 1.5f, 0.0f,           // Spitze
            1.0f, 0.0f, 0.0f                            // ROTE Farbe
        );

        erstelleQuadrat(//Tür
            hausX + 0.1f, hausY + 0.1f,                  // hausY + 0.1 statt festem -0.8f
            0.4f, 0.3f,
            1.0f, 1.0f, 1.0f
        );

        erstelleQuadrat(//Fenster
            hausX + 0.6f, hausY + 0.5f,                   // hausY + 0.5 statt festem -0.6f
            0.3f, 0.3f,
            0.0f, 0.0f, 1.0f
        );
        // ===== WICHTIG: Neue Vertices aus aktuellen Dreiecken =====
        vertexDaten = dreieckeZuVertices();

        // ===== WICHTIG: OpenGL Buffer aktualisieren =====
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertexDaten.size() * sizeof(float),
            vertexDaten.data(), GL_STATIC_DRAW);

        // ===== Shader und Zeichnen =====
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

        int location = glGetUniformLocation(shaderProgram, "offset");
        glUniform1f(location, position);

        glDrawArrays(GL_TRIANGLES, 0, vertexDaten.size() / 6);

        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}