�}
  �  {�.�j�yD    ���~�����V�����3�"�&�����\w�-���u�n��1޸WV�4��}�9\��ے2F3���Q��JL�mc_)�~{��z�# $e��S�� P���(�A��2��#.݆�
㓕[�H�B[<p��K-�!���@�M'��6�).�f_l���oL�(Zq�sr�sl	�$S5ن:۷���gq�m^�  M�!i[^O�B�3l^��=�
��!���8�'ɷy��(�h_����������3��z	��xN�y�KgydUUg��vr��B�K�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���ceneManager::FlushScene()
{
	Application& app = Engine::Instance().AppInstance();
	app.Update();
}

void SceneManager::SetCamera(CameraPtr camera)
{
	mCamera = camera;
}

CameraPtr SceneManager::GetCamera()
{
	return mCamera;
}
