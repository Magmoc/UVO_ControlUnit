import os
import datetime

Import("env")

def post_program_action(source, target, env):
	PROJECT_DIR = env.subst("$PROJECT_DIR")
	
	log_dir = "logs"
	log_path = os.path.join(PROJECT_DIR, log_dir)

	if not os.path.exists(log_path):
		os.mkdir(log_path)

	current_datetime = datetime.datetime.now()
	formatted_datetime = current_datetime.strftime("%Y-%m-%dT%H.%M.%S")

	log_filename = formatted_datetime + ".txt"
	log_path = os.path.join(log_path, log_filename)

	env.Execute(f"pio device monitor > {log_path}")

env.AddPostAction("upload", post_program_action)