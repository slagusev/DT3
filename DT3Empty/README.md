DT3Empty
========

Empty project to get started with DT3

1. Install Qt as per instructions in DT3 repo

2. Clone DT3 repo into a directory called src (at the same level as src_game)
        
    git clone https://github.com/smellslikedonkey/DT3.git src
    
3. Generate package files for iOS and Android. This builds the data.pack file that contains all of the assets.
    
    cd install
    
    ./makepkg.sh
    
4. Open XCode project
    - Build GameMac Debug
    - Build LevelEditor Debug
    - Build GameiOS