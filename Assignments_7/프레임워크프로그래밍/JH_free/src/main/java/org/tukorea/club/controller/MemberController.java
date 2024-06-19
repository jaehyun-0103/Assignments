package org.tukorea.club.controller;

import javax.servlet.http.HttpSession;

import org.tukorea.club.domain.MemberVO;
import org.tukorea.club.service.MemberService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
@RequestMapping(value = "/members")
public class MemberController {

	private static final Logger logger = LoggerFactory.getLogger(MemberController.class);

	@Autowired
	private MemberService memberService;

	@GetMapping("/join") // 1
	public String joinMemberGet() throws Exception {
		return "join";
	}

	@PostMapping("/join") // 2
	public String joinMemberPost(@ModelAttribute("member") MemberVO vo) throws Exception {
		try {
			memberService.addMember(vo);
			return "redirect:/";
		} catch (Exception e) {
			logger.info(" [회원가입 실패!]");
			return "redirect:/members/join";
		}
	}

	@PostMapping("/login") // 3
	public String loginMemberPost(@ModelAttribute("member") MemberVO vo, HttpSession session) throws Exception {
		Integer memberId = memberService.selectMember(vo);
		if (memberId != null) {
			session.setAttribute("memberId", memberId);
			return "redirect:/groups/list";
		} else {
			logger.info(" [로그인 실패!]");
			return "redirect:/";
		}
	}

	@GetMapping("/profile") // 8
	public String profileMemberGet(@RequestParam("id") int id, Model model) throws Exception {
		MemberVO member = memberService.readMember(id);

		model.addAttribute("member", member);
		return "mypage";
	}

	@PostMapping("/modify") // 9
	public String modifyMemberPost(@ModelAttribute("member") MemberVO vo) throws Exception {
		try {
			MemberVO vo1 = new MemberVO();
			MemberVO vo2 = new MemberVO();
			
			vo1.setMemberId(vo.getMemberId());
			vo1.setPassword(vo.getPassword());
			
			vo2.setMemberId(vo.getMemberId());
			vo2.setMemberName(vo.getMemberName());
			memberService.updateMember(vo1, vo2);
		} catch (Exception ex) {
			logger.info(" [회원 정보 수정 실패!]");
			ex.printStackTrace();
		}
		return "redirect:/groups/list";
	}

	@GetMapping("/delete/{id}") // 10
	public String deleteMemberGet(@PathVariable int id) throws Exception {
		memberService.deleteMember(id);
		return "redirect:/";
	}

	@GetMapping("/logout") // 14
	public String logoutMemberGet(HttpSession session) throws Exception {
		session.removeAttribute("memberId");
		return "redirect:/";
	}
}
