#include "svgfile.h"
#include <iostream>
#include <sstream>

const std::string svgHeader =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
    "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" ";

const std::string svgEnding = "\n\n</svg>\n";

/// Effets "Boule en relief", voir donn�es � la fin de ce fichier
extern const std::string svgBallGradients;

std::set<std::string> Svgfile::s_openfiles;

bool Svgfile::s_verbose = true;

Svgfile::Svgfile(std::string _filename, int _width, int _height) :
    m_filename{_filename}, m_width{_width}, m_height{_height}
{

    if (s_verbose)
        std::cout << "Opening SVG output file : "
                  << m_filename << std::endl;

    if ( s_openfiles.count(m_filename) )
        throw std::runtime_error( "File " + m_filename + " already open !" );

    m_ostrm.open(m_filename);
    s_openfiles.insert(m_filename);

    if (!m_ostrm)
    {
        std::cout << "Problem opening " << m_filename << std::endl;
        throw std::runtime_error("Could not open file " + m_filename );
    }

    if (s_verbose)
        std::cout << "OK" << std::endl;

    // Writing the header into the SVG file
    m_ostrm << svgHeader;
    m_ostrm << "width=\"" << m_width << "\" height=\"" << m_height << "\">\n\n";
}

Svgfile::~Svgfile()
{
    // Writing the ending into the SVG file
    m_ostrm << svgEnding;

    // Removing this file from the list of open files
    s_openfiles.erase(m_filename);

    // No need to explicitly close the ofstream object (automatic upon destruction)
}

// Helper templated function
template<typename T>
std::string attrib(std::string name, T val)
{
    std::ostringstream oss;
    oss << name << "=\"" << val << "\" ";
    return oss.str();
}
