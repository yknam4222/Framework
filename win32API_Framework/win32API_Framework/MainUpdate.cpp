#include "MainUpdate.h"
#include "SceneManager.h"

MainUpdate::MainUpdate() : m_pPlayer(NULL)
{

}

MainUpdate::~MainUpdate()
{
	Destroy();
}

void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	SceneManager::GetInstance()->SetScene(Logo);
}

void MainUpdate::Update()
{
	SceneManager::GetInstance()->Update();
	
}

void MainUpdate::Render()
{
	Rectangle(m_hdc, 0, 0, WIDTH, HEIGHT);

	


}

void MainUpdate::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}

	if (m_pEnemy)
	{
		delete m_pEnemy;
		m_pEnemy = NULL;
	}
}

