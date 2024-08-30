#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Función para manejar la respuesta de cURL
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Función para hacer la llamada a la API de traducción
std::string traducirPalabra(const std::string& palabra) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    // Validar que la palabra no esté vacía
    if (palabra.empty()) {
        std::cerr << "Error: La palabra a traducir no puede estar vacía." << std::endl;
        return "";
    }

    // Construimos la URL de la solicitud
    std::string url = "https://www.translated.net/hts/?f=quote&s=en-US&t=es-419&w=100&cid=htsdemo&p=htsdemo5&of=json&q=" + palabra;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        
        // Manejo de errores de cURL
        if (res != CURLE_OK) {
            std::cerr << "Error en cURL: " << curl_easy_strerror(res) << std::endl;
            curl_easy_cleanup(curl);
            return "";
        }
        
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Error: No se pudo inicializar cURL." << std::endl;
        return "";
    }

    return readBuffer; // Devuelve la respuesta de la API
}

int main() {
    std::string palabra;
    std::cout << "Introduce una palabra en inglés para traducir: ";
    std::getline(std::cin, palabra);

    // Llama a la función para traducir la palabra
    std::string response = traducirPalabra(palabra);

    // Verifica si la respuesta está vacía
    if (response.empty()) {
        std::cerr << "Error: La respuesta de la API está vacía." << std::endl;
        return 1; // Salir con un código de error
    }

    try {
        // Intenta parsear la respuesta JSON
        auto json_data = json::parse(response);
        // Acceder a la traducción si está presente
        if (json_data.contains("translatedText")) {
            std::cout << "Traducción: " << json_data["translatedText"] << std::endl;
        } else {
            std::cerr << "Error: La traducción no está disponible en la respuesta." << std::endl;
        }
    } catch (const json::parse_error& e) {
        std::cerr << "Error al parsear JSON: " << e.what() << std::endl;
        return 1; // Salir con un código de error
    }

    return 0; // Salida exitosa
}
