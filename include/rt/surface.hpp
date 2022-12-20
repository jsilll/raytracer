#pragma once

#include <rt/point.hpp>
#include <rt/ray.hpp>
#include <rt/vec3.hpp>

namespace rt {

/// @brief A surface in 3D space.
struct HitRecord
{
  /// @brief The offset of intersection point
  float t{ 0 };
  /// @brief The point of intersection.
  Point p{ 0, 0, 0 };
  /// @brief True if the ray is outside the surface.
  bool front_face{ false };
  /// @brief The normal of the surface at the intersection point.
  /// @note Should always be normalized and point in the opposite direction as the ray.
  Vec3f normal{ 0, 0, 0 };

  /**
   * @brief Sets the normal of the surface.
   * @param r The ray.
   * @param outwards_normal The normal of the surface. Should always be normalized and point in the outwards direction
   * of the surface.
   * @return
   */
  constexpr void set_face_normal(const Ray &r, const Vec3f &outwards_normal) noexcept
  {
    front_face = r.direction().Dot(outwards_normal) <= 0;
    normal = front_face ? outwards_normal : -outwards_normal;
  }
};

/// @brief A surface in 3D space.
class Surface
{
public:
  virtual ~Surface() = default;

  /**
   * @brief Returns whether the given ray intersects the surface.
   * @param r The ray to test.
   * @param t_min The minimum offset of the intersection point.
   * @param t_max The maximum offset of the intersection point.
   * @param rec The record of the intersection.
   * @return
   */
  [[nodiscard]] virtual bool Intersect(const Ray &ray, float t_min, float t_max, HitRecord &rec) const noexcept = 0;
};

}// namespace rt