#pragma once
class Bg
{
public:
	Bg();
	~Bg();

	void Init();
	void Update();
	void Draw();

private:
	int m_mainBgHandle;
};

