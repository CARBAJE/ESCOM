#include <iostream>
#include <curl/curl.h>

// Esta función será llamada por cURL cuando reciba datos
size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *buffer) {
    size_t total_size = size * nmemb;
    buffer->append((char*)contents, total_size);
    return total_size;
}

int main() {
    CURL *curl;
    CURLcode res;
    std::string buffer; // Aquí almacenaremos el contenido de la página web

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.nintenderos.com/2024/03/afirman-que-estos-son-los-19-vecinos-mas-adorables-ahora-en-animal-crossing-new-horizons/");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Error al obtener la página: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Contenido de la página web:" << std::endl;
            std::cout << buffer << std::endl;
        }

        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Error al inicializar cURL" << std::endl;
        return 1;
    }

    return 0;
}
