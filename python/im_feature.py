feature_key_map = globals().get("feature_key_map", {})


class IMFeatureAuthorizationSettings:

    def to_json(self):
        data = {}
        # for name in dir(self):
        #     value = getattr(self, name)
        #     if isinstance(value, dict):
        #         data[name] = value
        # ASL
        data["asl_global_translation"] = self.asl_global_translation
        data["asl_message_translation"] = self.asl_message_translation
        data["asl_typing_translation"] = self.asl_typing_translation
        data["asl_image_translation"] = self.asl_image_translation
        data["asl_set_translation_language"] = self.asl_set_translation_language
        # Calendar
        data["calendar_check_calendars"] = self.calendar_check_calendars
        data["calendar_create_event"] = self.calendar_create_event
        # CCM
        data["ccm_export_messages_to_doc"] = self.ccm_export_messages_to_doc
        data["ccm_send_doc"] = self.ccm_send_doc
        data["ccm_convert_file_to_online_doc"] = self.ccm_convert_file_to_online_doc
        # VC
        data["vc_start_video_conference"] = self.vc_start_video_conference
        # Task
        data["task_setting"] = self.task_setting
        # Moments
        data["moments_setting"] = self.moments_setting
        return data

    #
    # ASL
    #
    @property
    def asl_global_translation(self):
        if feature_key_map.get("IM_translation_function", True):
            return {"auth": True}
        else:
            return {"auth": False}

    @property
    def asl_message_translation(self):
        if feature_key_map.get("IM_translation_function", True):
            return {"auth": True}
        else:
            return {"auth": False}

    @property
    def asl_typing_translation(self):
        if feature_key_map.get("IM_translation_function", True):
            return {"auth": True}
        else:
            return {"auth": False}

    @property
    def asl_image_translation(self):
        if feature_key_map.get("IM_translation_function", True):
            return {"auth": True}
        else:
            return {"auth": False}

    @property
    def asl_set_translation_language(self):
        if feature_key_map.get("IM_translation_function", True):
            return {"auth": True}
        else:
            return {"auth": False}

    #
    # Calendar
    #
    @property
    def calendar_check_calendars(self):
        if feature_key_map.get("calendar_event_create_function", True):
            return {"auth": True}
        else:
            return {"auth": False}

    @property
    def calendar_create_event(self):
        if feature_key_map.get("calendar_event_create_function", True):
            return {"auth": True}
        else:
            return {"auth": False}

    #
    # CCM
    #
    @property
    def ccm_export_messages_to_doc(self):
        if feature_key_map.get("doc_create_function", True):
            return {"auth": True}
        else:
            return {"auth": False}

    @property
    def ccm_send_doc(self):
        if feature_key_map.get("doc_create_function", True):
            return {"auth": True}
        else:
            return {"auth": False}

    @property
    def ccm_convert_file_to_online_doc(self):
        if feature_key_map.get("doc_create_function", True):
            return {"auth": True}
        else:
            return {"auth": False}

    #
    # VC
    #
    @property
    def vc_start_video_conference(self):
        if feature_key_map.get("vc_video_conference_start_function", True):
            return {"auth": True}
        else:
            return {"auth": False}

    #
    # Task
    #
    @property
    def task_setting(self):
        if feature_key_map.get("task_enabled", True):
            return {"auth": True}
        else:
            return {"auth": False}

    #
    # Moments
    #
    @property
    def moments_setting(self):
        if feature_key_map.get("lark_moments", True):
            return {"auth": True}
        else:
            return {"auth": False}


def GetSettings():
    settings = IMFeatureAuthorizationSettings().to_json()
    print("settings: \n", settings)
    return settings


print(GetSettings())
