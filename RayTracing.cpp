#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>

#include "MMath.h"
#include "Utils.h"

int main() {
    int width = 256;
    int height = 256;

    std::vector<vec3f> framebuffer(width * height); // RGB values

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    // Loop through each pixel in the image
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            // Simulate ray tracing by printing pixel coordinates
            int r = static_cast<int>(double(i) * 255 / (width - 1));
            int g = static_cast<int>(double(j) * 255 / (height - 1));
            int b = 0; // For simplicity, we set blue to 0
            framebuffer[i * width + j] = vec3f(r, g, b);
        }
        Utils::instance()->UpdateProgress(static_cast<float>(i + 1) / height);
    }
    Utils::instance()->UpdateProgress(1.0f); // Complete the progress bar
    std::cout << std::endl;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " seconds" << std::endl;

    std::ofstream output("output.ppm");
    if (!output) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }
    output << "P3\n" << width << " " << height << "\n255\n";
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            vec3f color = framebuffer[i * width + j];
            output << color.x << " " << color.y << " " << color.z << "\n";
        }
    }
    output.close();
    std::cout << "Finished writing output.ppm" << std::endl;
    return 0;
}