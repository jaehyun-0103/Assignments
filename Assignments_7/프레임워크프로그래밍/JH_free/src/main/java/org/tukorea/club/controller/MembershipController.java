package org.tukorea.club.controller;

import org.tukorea.club.domain.MembershipVO;
import org.tukorea.club.service.MembershipService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping(value="/memberships")
public class MembershipController {
	private static final Logger logger = LoggerFactory.getLogger(MembershipController.class);

	@Autowired
    private MembershipService membershipService;
	
	@PostMapping("/contact") // 12
	public String contactMembershipPost( @ModelAttribute("member") MembershipVO vo) throws Exception {
		membershipService.addMember(vo);
		return "redirect:/groups/list";
	}
	
	@PostMapping("/delete") // 13
	public String deleteMembershipPost( @ModelAttribute("member") MembershipVO vo) throws Exception {
		membershipService.deleteMember(vo);
		return "redirect:/groups/list";
	}
}