�}.
    �3�|T    ��� �~·�O����t���^z��6\_�Ǧ�,J�`CL��shQ[�'E�Zj����}]���b�7S�7��rH}a�,�����v�u ��1����9�~.���l�E�?�����4B��N-�v?���|�� xo�.��)��ĕ[Bp��ź�����^��㩉3��`y2����b����R���u�D���ʮ#K_�zk[l�=jV?ߵW�o"�L�[&W���rNw��@"	��r���)Qv��}f����>B�K�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���stance_;
	}

	void Engine::Destroy()
	{

	}

	void Engine::Init()
	{
		renderer_ = std::shared_ptr<Renderer>(new Renderer());
		renderer_->Init();

		scene_mgr_ = std::shared_ptr<SceneManager>(new SceneManager());
		scene_mgr_->Init();
	}

}