#!/usr/bin/env python3
"""YOKO CAD render. Outputs STL + PNG. Requires: trimesh, numpy, matplotlib."""
import os, math, numpy as np
import trimesh
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection

palm_w, palm_l, palm_h = 78, 68, 14
phalanx_prox_l, phalanx_mid_l, phalanx_dist_l = 38, 26, 20
phalanx_w = 11
finger_angles = [-28, -14, 0, 14, 28]
finger_y_offset = [-26, -13, 0, 13, 26]

def build():
    meshes = [trimesh.creation.box(extents=[palm_l, palm_w, palm_h])]
    for i in range(5):
        ang, yoff = math.radians(finger_angles[i]), finger_y_offset[i]
        c, s = math.cos(ang), math.sin(ang)
        x0, z0 = palm_l/2, palm_h/2 + 3.5
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

def shade(verts, light=np.array([0.4, 0.4, 1.0])):
    light = light / np.linalg.norm(light)
    out, base = [], (0.55, 0.58, 0.62)
    for v in verts:
        n = np.cross(v[1]-v[0], v[2]-v[0])
        n = n / (np.linalg.norm(n) + 1e-8)
        i = max(0.45, min(0.95, np.dot(n, light)*0.4 + 0.7))
        out.append((base[0]*i, base[1]*i, base[2]*i, 1.0))
    return out

def main():
    d = os.path.join(os.path.dirname(__file__), "cad-images")
    os.makedirs(d, exist_ok=True)
    mesh = build()
    mesh.export(os.path.join(d, "yoko_assembly.stl"))
    verts = mesh.vertices[mesh.faces]
    for (elev, azim), name in [((22, 48), "1"), ((18, 118), "2")]:
        fig = plt.figure(figsize=(5, 5), dpi=200)
        ax = fig.add_subplot(111, projection='3d')
        ax.add_collection3d(Poly3DCollection(verts, facecolors=shade(verts), edgecolors='#5a6268', linewidths=0.25, alpha=1))
        ax.set_xlim(mesh.vertices[:,0].min()-3, mesh.vertices[:,0].max()+3)
        ax.set_ylim(mesh.vertices[:,1].min()-3, mesh.vertices[:,1].max()+3)
        ax.set_zlim(mesh.vertices[:,2].min()-3, mesh.vertices[:,2].max()+3)
        ax.set_box_aspect([1,1,1])
        ax.view_init(elev=elev, azim=azim)
        ax.set_facecolor('#f5f5f5')
        for p in [ax.xaxis, ax.yaxis, ax.zaxis]:
            p.pane.fill = False
            p.pane.set_edgecolor('#e0e0e0')
        ax.axis('off')
        plt.tight_layout(pad=0.2)
        plt.savefig(os.path.join(d, f"yoko-cad-viewport-{name}.png"), dpi=200, bbox_inches='tight', facecolor='#f5f5f5')
        plt.close()
    print("Rendered yoko-cad-viewport-1.png, yoko-cad-viewport-2.png")

if __name__ == "__main__":
    main()
