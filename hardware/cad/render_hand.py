#!/usr/bin/env python3
"""YOKO — CAD render: trimesh + matplotlib. Outputs yoko-cad-viewport-1/2.png"""
import os, math, numpy as np
import trimesh
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection

palm_w, palm_l, palm_h = 78, 68, 14
phalanx_prox_l, phalanx_mid_l, phalanx_dist_l = 38, 26, 20
phalanx_w, phalanx_h = 11, 7
finger_angles = [-28, -14, 0, 14, 28]
finger_y_offset = [-26, -13, 0, 13, 26]

def build():
    meshes = [trimesh.creation.box(extents=[palm_l, palm_w, palm_h])]
    for i in range(5):
        ang, yoff = math.radians(finger_angles[i]), finger_y_offset[i]
        c, s = math.cos(ang), math.sin(ang)
        x0, z0 = palm_l/2, palm_h/2 + phalanx_h/2
        def place(r, h, seg):
            cyl = trimesh.creation.cylinder(radius=r, height=h)
            cyl.apply_transform(trimesh.transformations.rotation_matrix(np.pi/2, [0,1,0]))
            cyl.apply_transform(trimesh.transformations.rotation_matrix(ang, [0,0,1]))
            cyl.apply_translation([x0 + seg*c, yoff + seg*s, z0])
            return cyl
        meshes.append(place(phalanx_w/2, phalanx_prox_l, phalanx_prox_l/2))
        meshes.append(place(phalanx_w*0.9/2, phalanx_mid_l, phalanx_prox_l + 8 + phalanx_mid_l/2))
        meshes.append(place(phalanx_w*0.85/2, phalanx_dist_l, phalanx_prox_l + 16 + phalanx_mid_l + phalanx_dist_l/2))
    return trimesh.util.concatenate(meshes)

def main():
    d = os.path.join(os.path.dirname(__file__), "cad-images")
    os.makedirs(d, exist_ok=True)
    mesh = build()
    mesh.export(os.path.join(d, "yoko_assembly.stl"))
    fig = plt.figure(figsize=(8,6))
    ax = fig.add_subplot(111, projection='3d')
    verts = mesh.vertices[mesh.faces]
    ax.add_collection3d(Poly3DCollection(verts, facecolors='#b0b8c0', edgecolors='none', alpha=0.95))
    ax.auto_scale_xyz(mesh.vertices[:,0], mesh.vertices[:,1], mesh.vertices[:,2])
    ax.set_facecolor('white')
    ax.xaxis.pane.fill = ax.yaxis.pane.fill = ax.zaxis.pane.fill = False
    ax.view_init(elev=20, azim=45)
    ax.axis('off')
    plt.savefig(os.path.join(d, "yoko-cad-viewport-1.png"), dpi=150, bbox_inches='tight', facecolor='white')
    ax.view_init(elev=20, azim=120)
    plt.savefig(os.path.join(d, "yoko-cad-viewport-2.png"), dpi=150, bbox_inches='tight', facecolor='white')
    plt.close()
    print("Rendered yoko-cad-viewport-1.png, yoko-cad-viewport-2.png")

if __name__ == "__main__":
    main()
