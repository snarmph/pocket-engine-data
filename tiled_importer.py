import json
from xml.etree import ElementTree as ET

def index_to_list(index, map):
    res = []

    counter = 0
    for layer in map["layers"]:
        l = {
            "layer": counter,
            "indices": []
        }
        zeros = 0
        for i in range(len(layer)):
            if layer[i] == 0:
                zeros += 1
            elif layer[i] == index:
                l["indices"].append(i - zeros)
        if len(l["indices"]) > 0:
            res.append(l)
        counter += 1

    return res

filedir = "tiled/"
fname = "pallet-town"
map_tree = ET.parse(filedir + fname + ".tmx")
maproot = map_tree.getroot()

tileset_file = maproot.findall('./tileset[1]')[0].attrib["source"]

tileset_tree = ET.parse(filedir + tileset_file)
tileset_root = tileset_tree.getroot()

should_be = {
    "animations": [
        {
            "indices": [[], [0, 2], [1]],
            "animation": [
                {
                    "index": 4,
                    "duration": 400
                }
            ]
        }
    ],
	"layers": [
		[0, 1, 2],
		[3, 4, 5],
		[6, 7, 8]
	],
	"tileset": {
		"filename": "",
		"tilesize": 16
	},
	"width": 24,
	"height": 24
}

out = {
	"layers": [],
	"tileset": {},
    "animations": []
}

out["width"] = int(maproot.attrib["width"])
out["height"] = int(maproot.attrib["height"])

out["tileset"]["tilesize"] = int(maproot.attrib["tilewidth"])
out["tileset"]["filename"] = "data/tilesets/" + tileset_root.attrib["name"] + ".png"

count = 0
for layer in maproot.iter("layer"):
    data = layer[0].text
    data = data.split(",")

    out["layers"].append([])

    for num in data:
        out["layers"][count].append(int(num))

    count += 1
    if(count > 4):
        print("ERROR: TOO MANY LAYERS")
        exit(1)

for anim in tileset_root.findall(".//animation"):
    first = True
    skip = True
    for frame in anim.iter("frame"):
        index = int(frame.attrib["tileid"])
        if first:
            found = index_to_list(index+1, out)
            for f in found:
                if len(f) > 0:
                    skip = False
            if skip:
                continue
            out["animations"].append({
                "index_data": found,
                "animation": []
            })
            first = False
        if skip:
            continue
        current = out["animations"][-1]["animation"]
        current.append({
            "index": index,
            "duration": float(frame.attrib["duration"]) / 1000.0
        })

    #     if first:
    #         out["animations"].append({
    #                 "index": int(frame.attrib["tileid"]),
    #                 "animation": []
    #             })
    #         first = False
    #     current = out["animations"][-1]["animation"]
    #     current.append({
    #         "index": int(frame.attrib["tileid"]),
    #         "duration": int(frame.attrib["duration"])
    #     })
    #     print(">", current)
    # print("")

outfile = open("maps/" + fname + ".json", "w")
outfile.write(json.dumps(out, indent=4))
outfile.close()
print("written file to disk")
