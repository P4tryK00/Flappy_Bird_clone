//
// Created by patryk on 20.07.2026.
//

#ifndef FLAPPY_BIRD_CLONE_RESOURCEMANAGER_H
#define FLAPPY_BIRD_CLONE_RESOURCEMANAGER_H

class ResourceManager {
public:
    ResourceManager() = delete;

    static void loadAllResources();
    static void cleanUpAllResources();
};


#endif //FLAPPY_BIRD_CLONE_RESOURCEMANAGER_H
