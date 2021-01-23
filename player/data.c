#include "data.h"

data dataObject = {
    .size = {
        .x = 16, 
        .y = 24
    }, 
    .texture = "data/sprites/red.png", 
    .animations = {
        {
            .name = "walk-down", 
            .frames = {
                .length = 4, 
                .values = (dataAnimationsEntryFramesValues[]){
                    {0.0, 0.15}, 
                    {1.0, 0.15}, 
                    {2.0, 0.15}, 
                    {1.0, 0.15}
                }
            }, 
            .repeat = true
        }, 
        {
            .name = "walk-up", 
            .frames = {
                .length = 4, 
                .values = (dataAnimationsEntryFramesValues[]){
                    {6.0, 0.15}, 
                    {7.0, 0.15}, 
                    {8.0, 0.15}, 
                    {7.0, 0.15}
                }
            }, 
            .repeat = true
        }, 
        {
            .name = "walk-left", 
            .frames = {
                .length = 4, 
                .values = (dataAnimationsEntryFramesValues[]){
                    {12.0, 0.15}, 
                    {13.0, 0.15}, 
                    {14.0, 0.15}, 
                    {13.0, 0.15}
                }
            }, 
            .repeat = true
        }, 
        {
            .name = "walk-right", 
            .frames = {
                .length = 4, 
                .values = (dataAnimationsEntryFramesValues[]){
                    {18.0, 0.15}, 
                    {19.0, 0.15}, 
                    {20.0, 0.15}, 
                    {19.0, 0.15}
                }
            }, 
            .repeat = true
        }, 
        {
            .name = "look-down", 
            .frames = {
                .length = 1, 
                .values = (dataAnimationsEntryFramesValues[]){
                    {1.0, 0.15}
                }
            }, 
            .repeat = false
        }, 
        {
            .name = "look-up", 
            .frames = {
                .length = 1, 
                .values = (dataAnimationsEntryFramesValues[]){
                    {7.0, 0.15}
                }
            }, 
            .repeat = false
        }, 
        {
            .name = "look-left", 
            .frames = {
                .length = 1, 
                .values = (dataAnimationsEntryFramesValues[]){
                    {13.0, 0.15}
                }
            }, 
            .repeat = false
        }, 
        {
            .name = "look-right", 
            .frames = {
                .length = 1, 
                .values = (dataAnimationsEntryFramesValues[]){
                    {19.0, 0.15}
                }
            }, 
            .repeat = false
        }
    }, 
    .initialstate = "look-down"
};

