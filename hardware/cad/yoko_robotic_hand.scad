// YOKO — 3D-Printed Robotic Hand
// OpenSCAD parametric CAD model
// Based on: 5 fingers, 3 phalanxes per finger, joints, palm, motor mounts
// Compatible with hardware/stl/ part naming; see hardware/cad/README.md

// ========== PARAMETERS ==========
$fn = 32;

// Palm
palm_w = 80;   // width (thumb to pinky)
palm_l = 70;   // length (wrist to knuckles)
palm_h = 15;   // height (thickness)

// Phalanx dimensions (mm) — prox/mid/dist per finger
phalanx_prox_l = 40;  // proximal length
phalanx_mid_l  = 28;  // middle length
phalanx_dist_l = 22;  // distal length
phalanx_w = 12;       // width (cross-section)
phalanx_h = 8;        // height (cross-section)

// Joint
joint_d = 10;         // joint pin diameter
joint_clearance = 0.3; // pin/boss clearance for tolerance iteration

// Motor mount
mount_w = 25;
mount_l = 30;
mount_h = 12;

// Finger spread (degrees from center)
finger_angles = [-20, -10, 0, 10, 20];  // thumb, index, middle, ring, pinky

// ========== MODULES ==========

module phalanx(length, label="") {
  // Rounded finger segment
  hull() {
    translate([0, 0, 0]) cylinder(h=phalanx_h/2, d=phalanx_w);
    translate([length, 0, 0]) cylinder(h=phalanx_h/2, d=phalanx_w*0.9);
  }
  translate([length/2, 0, phalanx_h/4]) 
    linear_extrude(1) text(label, size=3, halign="center", valign="center");
}

module joint() {
  difference() {
    cylinder(h=phalanx_h*1.2, d=joint_d + 2, center=true);
    cylinder(h=phalanx_h*1.5, d=joint_d + joint_clearance, center=true);
  }
}

module motor_mount() {
  difference() {
    cube([mount_l, mount_w, mount_h], center=true);
    cylinder(h=mount_h+2, d=6, center=true);
    for (dx=[-9,9], dy=[-7,7]) 
      translate([dx, dy, 0]) cylinder(h=mount_h+2, d=2.2, center=true);
  }
}

module palm() {
  difference() {
    hull() {
      translate([0, 0, palm_h/2]) cube([palm_l, palm_w, palm_h], center=true);
      translate([-palm_l/4, 0, palm_h/2]) cylinder(h=palm_h, d=palm_w*0.8, center=true);
    }
    // Cable routing cavity
    translate([0, 0, palm_h/2+2]) 
      cube([palm_l-20, palm_w-25, palm_h-4], center=true);
  }
}

module finger(angle) {
  rotate([0, 0, angle]) {
    translate([palm_l/2 + phalanx_prox_l/2, 0, palm_h + phalanx_h/2]) {
      phalanx(phalanx_prox_l, "P");
      translate([phalanx_prox_l, 0, 0]) {
        joint();
        translate([joint_d/2 + phalanx_mid_l/2, 0, 0]) {
          phalanx(phalanx_mid_l, "M");
          translate([phalanx_mid_l, 0, 0]) {
            joint();
            translate([joint_d/2 + phalanx_dist_l/2, 0, 0]) 
              phalanx(phalanx_dist_l, "D");
          }
        }
      }
    }
  }
}

module finger_motor_mount(angle) {
  rotate([0, 0, angle])
    translate([palm_l/2 + mount_l/2 + 5, 0, -mount_h/2 - 2])
      motor_mount();
}

// ========== ASSEMBLY ==========

module yoko_assembly() {
  color([0.85, 0.85, 0.9]) palm();
  
  for (i = [0:4]) {
    color([0.7 + i*0.06, 0.75, 0.85]) 
      finger(finger_angles[i]);
    color([0.6, 0.6, 0.65]) 
      finger_motor_mount(finger_angles[i]);
  }
}

// Render full assembly (for view/preview)
yoko_assembly();

// ========== INDIVIDUAL PARTS (for STL export) ==========
// Uncomment one at a time, render (F6), then File → Export as STL

// translate([0, 0, 0]) phalanx(phalanx_prox_l);  // yoko_phalanx_prox_v1
// translate([0, 0, 0]) phalanx(phalanx_mid_l);   // yoko_phalanx_mid_v1
// translate([0, 0, 0]) phalanx(phalanx_dist_l);  // yoko_phalanx_dist_v1
// joint();                                        // yoko_joint_v1
// motor_mount();                                  // yoko_motor_mount_v1
// palm();                                         // yoko_palm_base_v1
