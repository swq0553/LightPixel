�}7
    ��8�"/�    ���~�i릳?�(�ٗY��% ���u&�v�ͣ��p|�-��<�M�f��h*0���s�4��M�K8�`C������-�!h���U�w��aG�:ACΒ��x�7����∠�QZ�eq؀'�8Ԯ:/�o?�Q�q-���2�=�a�&�<��qΎ�,�W��j˻X9���(ܔ�VLڑ��4t!�����Ͷ�1���px����d ��= �2
bC�=�L���N/"W@�c�!���sl�x���#�R^��-%�lO�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���nagerPtr SceneManagerInstance()
		{
			return scene_mgr_;
		}
		bool RendererValid() const
		{
			return !!renderer_;
		}
		RendererPtr RendererInstance()
		{
			return renderer_;
		}
	private:
		static std::shared_ptr<Engine> engine_instance_;

		Application*		app_;
		SceneManagerPtr		scene_mgr_;
		RendererPtr         renderer_;
	};
}

#endif

