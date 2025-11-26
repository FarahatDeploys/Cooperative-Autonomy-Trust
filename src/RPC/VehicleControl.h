#pragma once

#include "carla/MsgPack.h"
#include "carla/geom/Vector3D.h"  // Include for augmented reality path

#ifdef LIBCARLA_INCLUDED_FROM_UE4
#  include "Carla/Vehicle/VehicleControl.h"
#endif // LIBCARLA_INCLUDED_FROM_UE4

#include <vector>  // Include for the augmented reality path as a list of vectors

namespace carla {
    namespace rpc {

        class VehicleControl {
        public:

            VehicleControl() = default;

            VehicleControl(
                float in_throttle,
                float in_steer,
                float in_brake,
                bool in_hand_brake,
                bool in_reverse,
                bool in_manual_gear_shift,
                int32_t in_gear,
                const std::vector<carla::geom::Vector3D>& in_augmented_reality_path = {})
                : throttle(in_throttle),
                steer(in_steer),
                brake(in_brake),
                hand_brake(in_hand_brake),
                reverse(in_reverse),
                manual_gear_shift(in_manual_gear_shift),
                gear(in_gear),
                augmented_reality_path(in_augmented_reality_path) {}

            float throttle = 0.0f;
            float steer = 0.0f;
            float brake = 0.0f;
            bool hand_brake = false;
            bool reverse = false;
            bool manual_gear_shift = false;
            int32_t gear = 0;

            // Augmented reality path as a vector of 3D points
            std::vector<carla::geom::Vector3D> augmented_reality_path = {};

#ifdef LIBCARLA_INCLUDED_FROM_UE4

            // Corrected constructor conversion: FVehicleControl -> VehicleControl
            VehicleControl(const FVehicleControl& Control)
                : throttle(Control.Throttle),
                steer(Control.Steer),
                brake(Control.Brake),
                hand_brake(Control.bHandBrake),
                reverse(Control.bReverse),
                manual_gear_shift(Control.bManualGearShift),
                gear(Control.Gear) {
                // Convert from TArray<FVector> (Unreal) to std::vector<carla::geom::Vector3D> (C++)
                augmented_reality_path.clear();  // Ensure vector is empty before pushing
                for (const FVector& point : Control.AugmentedRealityPath) {
                    augmented_reality_path.emplace_back(point.X, point.Y, point.Z);
                }
            }


            // Corrected conversion: VehicleControl -> FVehicleControl
            operator FVehicleControl() const {
                FVehicleControl Control;
                Control.Throttle = throttle;
                Control.Steer = steer;
                Control.Brake = brake;
                Control.bHandBrake = hand_brake;
                Control.bReverse = reverse;
                Control.bManualGearShift = manual_gear_shift;
                Control.Gear = gear;
                // Convert from std::vector<carla::geom::Vector3D> (C++) to TArray<FVector> (Unreal)
                Control.AugmentedRealityPath.Empty();  // Ensure array is empty before adding points
                for (const carla::geom::Vector3D& point : augmented_reality_path) {
                    Control.AugmentedRealityPath.Add(FVector(point.x, point.y, point.z));
                }
                return Control;
        }


#endif // LIBCARLA_INCLUDED_FROM_UE4

            bool operator!=(const VehicleControl& rhs) const {
                return
                    throttle != rhs.throttle ||
                    steer != rhs.steer ||
                    brake != rhs.brake ||
                    hand_brake != rhs.hand_brake ||
                    reverse != rhs.reverse ||
                    manual_gear_shift != rhs.manual_gear_shift ||
                    gear != rhs.gear ||
                    augmented_reality_path != rhs.augmented_reality_path;
            }

            bool operator==(const VehicleControl& rhs) const {
                return !(*this != rhs);
            }

            MSGPACK_DEFINE_ARRAY(
                throttle,
                steer,
                brake,
                hand_brake,
                reverse,
                manual_gear_shift,
                gear,
                augmented_reality_path);  // Include augmented reality path in serialization
        };

    } // namespace rpc
} // namespace carla
