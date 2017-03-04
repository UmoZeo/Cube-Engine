#ifndef TZW_PLAYER_H
#define TZW_PLAYER_H

#include "Game/FPSCamera.h"
#include "EngineSrc/3D/Model/Model.h"
#include "3D/Primitive/SpherePrimitive.h"
#include "3D/Primitive/CubePrimitive.h"
namespace tzw {

class CubePlayer : public Node, public EventListener
{
public:
	enum class Mode
	{
		MODE_DEFORM_SPHERE,
		MODE_PLACE_CUBE,
		MODE_PLACE_SPHERE,
	};
    CubePlayer(Node * mainRoot);
    FPSCamera *camera() const;
    void setCamera(FPSCamera *camera);
    vec3 getPos();
    virtual void logicUpdate(float dt);
	bool checkIsNeedUpdateChunk();
	virtual bool onKeyPress(int keyCode);
	virtual bool onKeyRelease(int keyCode);
	virtual bool onMousePress(int button,vec2 pos);
	void modeSwitch(Mode newMode);
private:
	void updatePlaceHolder();
	Mode m_currMode;
    FPSCamera * m_camera;
    Model * m_gunModel;
	int oldPosX;
	int oldPosZ;
	CubePrimitive * m_placeHolder;
};

} // namespace tzw

#endif // TZW_PLAYER_H
