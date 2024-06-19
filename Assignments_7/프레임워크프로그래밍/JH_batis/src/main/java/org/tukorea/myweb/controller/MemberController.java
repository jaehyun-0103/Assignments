package org.tukorea.myweb.controller;

import java.nio.charset.Charset;
import java.util.List;

import org.tukorea.myweb.domain.StudentVO;
import org.tukorea.myweb.service.MemberService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
@RequestMapping(value = "/member")
public class MemberController {

	@Autowired
	private MemberService memberService;

	private static final Logger logger = LoggerFactory.getLogger(MemberController.class);

	@RequestMapping(value = { "/list" }, method = RequestMethod.GET)
	public String listMember(Model model) throws Exception {
		List<StudentVO> students = memberService.readMemberList();

		logger.info(" /member/list URL called. then listMemebr method executed.");
		model.addAttribute("students", students);
		return "member/member_list";
	}

	@RequestMapping(value = "/read", method = RequestMethod.GET)
	public String readMember(@RequestParam("id") String id, Model model) throws Exception {
		StudentVO student = memberService.readMember(id);

		logger.info(" /read?id=? URL called. then readMemebr method executed.");
		model.addAttribute("student", student);
		return "member/member_read";
	}

	@RequestMapping(value = { "/register" }, method = RequestMethod.GET)
	public String createMemberGet() throws Exception {
		logger.info(" /register URL GET method called. then forward member_register.jsp.");
		return "member/member_register";
	}

	@PostMapping("/register")
	public String createMemberPost(@ModelAttribute("student") StudentVO vo) throws Exception {
		memberService.addMember(vo);
		logger.info(vo.toString());
		logger.info(" /register URL POST method called. then createMember method executed.");
		return "redirect:/member/list";
	}

	@RequestMapping(value = "/modify", method = RequestMethod.GET)
	public String modifyMemberGet(@RequestParam("id") String id, Model model) throws Exception {
		StudentVO student = memberService.readMember(id);

		logger.info(" /modify?id=? URL GET method called. then forward member_modify.jsp.");
		model.addAttribute("student", student);
		return "member/member_modify";
	}

	@RequestMapping(value = "/modify", method = RequestMethod.POST)
	public String modifyMemberPost(@ModelAttribute("student") StudentVO vo) throws Exception {
		memberService.updateMember(vo);
		logger.info(vo.toString());
		logger.info(" /modify?id=? URL POST method called. then modifyMemberPost method executed.");
		return "redirect:/member/list";
	}

	@RequestMapping(value = "/delete", method = RequestMethod.GET)
	public String deleteMemberGet(@RequestParam("id") String id) throws Exception {
		memberService.deleteMember(id);

		logger.info(" /delete?id=? URL GET method called. listMemebr method executed.");
		return "redirect:/member/list";
	}
	
	// http://localhost:8080/myweb/member/rest/kang
	@RequestMapping(value = "/rest/{id}", method = RequestMethod.GET)
	public ResponseEntity<StudentVO> readMember(@PathVariable String id) throws Exception {
		StudentVO student = memberService.readMember(id);

		logger.info(" /rest/{id} REST-API GET method called. then readMember method executed.");
		HttpHeaders headers = new HttpHeaders();
		headers.setContentType(new MediaType("application", "json", Charset.forName("UTF-8")));
		headers.set("My-Header", "MyHeaderValue");
		return new ResponseEntity<StudentVO>(student, headers, HttpStatus.OK);
	}

	// http://localhost:8080/myweb/member/rest
	// {"id":"son","passwd":"pwd","username":"hokong","snum":"20181111","depart":"computer","mobile":"010-2424-333","email":"son@tukorea.ac.kr"}
	@RequestMapping(value = "/rest", method = RequestMethod.POST)
	public String restMemberPost(@RequestBody StudentVO vo) throws Exception {
		memberService.addMember(vo);

		logger.info(vo.toString());
		logger.info(" /rest/{id} REST-API POST method called. then createMemberPost method executed.");
		return "OK";
	}
}