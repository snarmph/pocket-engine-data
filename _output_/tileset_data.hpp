#pragma once
#include <pocket/core/types.hpp>
#include <pocket/containers/containers.hpp>

namespace pocket {
	struct animation_data {
		u32 index;
		u32 duration;
	};

	struct animation_t {
		u32 index;
		vector<animation_data> animation;
	};

	struct tileset_t {
		string filename;
		u32 tilesize;
	};

	struct tilemap {
		vector<animation_t> animations;
		vector<vector<u32>> layers;
		tileset_t tileset;
		u32 width;
		u32 height;
	};

	void read_tilemap(tilemap *data, const char *fname);
	void write_tilemap(tilemap *data, const char *fname);
 } // namespace pocket
