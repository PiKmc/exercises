import shutil
import json
import os

print("Generating REST handler.")

print("Preparing backup")
if os.path.exists("handler.cpp"):
    shutil.copyfile("handler.cpp", "tmp_handler.cpp")

start = -1
end = -1

with open('handler.cpp') as f:
    lines = f.readlines()

cnt = 0
for line in lines:
    if line.startswith("void handler::prepareGetResponse"):
        start = cnt
    if (start > -1) and (cnt > start) and (line.startswith("}")):  
        end = cnt
    cnt+=1

sub_text1 = lines[0:start+3]
sub_text2 = []
sub_text3 = lines[end:cnt]

with open("api.json") as f:
    data = json.load(f)

first = True
for item in data:
    if first:
        sub_text2.append("        if(req.target() == \"" + item["endpoint"] + "\") {\n")
        first = False
    else:
        sub_text2.append("        else if(req.target() == \"" + item["endpoint"] + "\") {\n")
    sub_text2.append("                nlohmann::json j = {{\"message\", \"" + item["message"] + "\"}};\n")
    sub_text2.append("                resp.set(http::field::content_type, \"application/json\");\n")
    sub_text2.append("                boost::beast::ostream(resp.body()) << j.dump();\n")
    sub_text2.append("                resp.prepare_payload();\n")
    sub_text2.append("        }\n")

sub_text2.append("        else {\n")
sub_text2.append("                resp.result(http::status::not_found);\n")
sub_text2.append("                resp.set(http::field::content_type, \"text/plain\");\n")
sub_text2.append("                boost::beast::ostream(resp.body()) << \"File not found\";\n")
sub_text2.append("        }\n")        
            
if os.path.exists("handler.cpp"):
    os.remove("handler.cpp");

with open('handler.cpp', 'w+') as f:    
    # write elements of list
    for items in sub_text1:
        f.write('%s' %items)
    for items in sub_text2:
        f.write('%s' %items)
    for items in sub_text3:
        f.write('%s' %items)

print("Finished sucessfully")

