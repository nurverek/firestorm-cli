#ifndef FSWAVEFRONT
#define FSWAVEFRONT

#include "fsm.h"
#include "loadconfig.h"

#include <string>
#include <vector>

namespace fs{
    class wavefront;
    class face;
};

class fs::face{
public:

    int positionindex;
    int uvindex;
    int normalindex;

    explicit face(int pindex, int uindex, int nindex);
    ~face();
};

class fs::wavefront{
    private:

        class data;
        class vertexdata;

        std::vector<float> tmppositions;
        std::vector<float> tmpcolors;
        std::vector<float> tmptexcoords;
        std::vector<float> tmpnormals;

        std::vector<face*> faces;
        std::vector<face*> tracker;
        
        int positioncount;
        int uvcount;
        int normalcount;

        void readName(entry *data, std::string &line);
        void readPosition(std::string &line);
        void readUV(std::string &line);
        void readNormal(std::string &line);
        void readFaces(std::string &line);
        void resolve(entry *data, bool showprogress);
        void reset();
        void clear();

    public:

        explicit wavefront();
        ~wavefront();

        void load(fsm &fsm, loadconfig &config, std::string &location, bool showprogress);
};

#endif