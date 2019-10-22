#pragma once
#include "Attachment.h"
#include "Base/GuidObj.h"
#include "Collision/PhysicsShape.h"
#include "Interface/Drawable3D.h"
#include "Math/Ray.h"
#include "rapidjson/document.h"

#define GAME_PART_BLOCK 0
#define GAME_PART_CYLINDER 1
#define GAME_PART_LIFT 2
#define GAME_PART_CONTROL 3
#define GAME_PART_THRUSTER 4
#define GAME_PART_CANNON 5
#define GAME_PART_NOT_VALID 999

namespace tzw {
class GamePart;
class BearPart;
class Island;

class GamePart : public GuidObj
{
public:
  virtual Drawable3D* getNode() const;
  virtual void setNode(Drawable3D* node);
  virtual PhysicsShape* getShape();
  virtual Attachment* findProperAttachPoint(Ray ray,
                                            vec3& attachPosition,
                                            vec3& Normal,
                                            vec3& up);
  virtual void attachTo(Attachment* attach);
  virtual Matrix44 attachToFromOtherIsland(Attachment* attach);
  virtual Matrix44 attachToFromOtherIslandAlterSelfIsland(
    Attachment* attach,
    Attachment* ownAttachment = nullptr);
  virtual Matrix44 adjustFromOtherIslandAlterSelfIsland(Attachment* attach,
                                                        Attachment* selfAttach);
  virtual Matrix44 adjustFromOtherIsland(Attachment* attach,
                                         Attachment* selfAttach);
  virtual Attachment* getFirstAttachment();
  virtual Attachment* getBottomAttachment();
  virtual Attachment* getTopAttachment();
  virtual Attachment* getAttachment(int index);
  virtual int getAttachmentCount();
  virtual Attachment* getAttachmentInfo(int index,
                                        vec3& pos,
                                        vec3& N,
                                        vec3& up);
  Island* m_parent;
  GamePart();
  virtual ~GamePart();
  virtual int getType();
  virtual float getMass();
  virtual void load(rapidjson::Value& partData);
  virtual void dump(rapidjson::Value& partDocObj,
                    rapidjson::Document::AllocatorType& allocator);

  virtual bool isConstraint();
  virtual vec3 getWorldPos();
  std::string getName() const;
  virtual void setName(std::string newName);
  virtual void generateName();
  std::string genShortName();
  virtual void highLight();
  virtual void unhighLight();
  virtual void use();

protected:
  std::string m_name;
  PhysicsShape* m_shape;
  Drawable3D* m_node;
};
}