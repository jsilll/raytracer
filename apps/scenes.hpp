#pragma once

#include <rt/camera.hpp>
#include <rt/primitives/sphere.hpp>
#include <rt/scene.hpp>

#include <utility>

namespace scenes {

/**
 * @brief Creates a scene with a single sphere and
 * another larger sphere as ground for casting shadows.
 * @return
 */
[[nodiscard]] std::pair<rt::Scene, rt::Camera> SphereWithGround(double aspect_ratio) noexcept;

}// namespace scenes