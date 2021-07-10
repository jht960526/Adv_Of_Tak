#pragma once


class Object;

class Scene
{
public:
	Scene();
	Scene(stack<Scene*>* scenes,RenderWindow* window);
	virtual ~Scene();

protected:

	vector<Object*> vObjects;

	map<string,Text*> mTexts;

	stack<Scene*>* scenes;
	bool quit = false;

	Object* backGround = nullptr;

private:

	virtual void Init();

public:

	bool GetQuit() const;
	void EndScene();

	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

